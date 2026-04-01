import argparse
import re
import sys
from typing import List, Dict, Set, Tuple

from double_init import find_double_initializations
from dtypes import Id, DFInfo, CF, AwaitedDF, CodeMetaInformation, CallHistory
from formatting import print_double_initialization_report, print_hang_report
from load import load_cf_info, load_id_map, load_pending, load_meta_info
from hang_analysis import build_dependency_graph, find_independent
from util import group_cfs, c


def parse_args(argv: List[str]) -> argparse.Namespace:
    parser = argparse.ArgumentParser(
        prog='luna_trace', description='Analyze trace files and report errors.')
    parser.add_argument('logs', type=str, nargs='+',
                        help='filled automatically')
    parser.add_argument(
        '--all', action='store_true',
        help='print all hang CFs; default: print only those which do not have data dependencies on other hang CFs')
    parser.add_argument(
        '--no-double-init', action='store_true',
        help='do not look for double initialization errors (will probably increase performance)'
    )

    return parser.parse_args(argv)


def main(argv: List[str]) -> None:
    args = parse_args(argv)

    pending_file_names: List[str] = list(filter(lambda s: re.match(r'pending\.\d+\.json.list', s), args.logs))
    id_info_file_names: List[str] = list(filter(lambda s: re.match(r'id\.\d+\.map\.list', s), args.logs))
    cf_info_file_names: List[str] = list(filter(lambda s: re.match(r'cf\.\d+\.json\.list', s), args.logs))

    cf_info: Dict[Id, CF] = load_cf_info(cf_info_file_names)
    df_info: Dict[Id, DFInfo] = load_id_map(id_info_file_names)
    pending: Dict[Id, List[AwaitedDF]] = load_pending(pending_file_names)

    meta: CodeMetaInformation = load_meta_info()

    # Search for `Double Initialization Errors`
    if not args.no_double_init:
        double_initializations = find_double_initializations(cfs=cf_info)
        print_double_initialization_report(
            double_initializations,
            cfs=cf_info,
            dfs=df_info,
            meta=meta
        )

    initial_pending_count: int = len(pending)

    if not args.all:
        # Search `Hang Causes`
        dependencies: Dict[Id, Set[Id]] = build_dependency_graph(
            pending,
            cfs=cf_info
        )
        hang_causes: Set[Id] = find_independent(dependencies)

        if hang_causes:
            print(f'Following CFs appear to be the {c("root cause")} of the system hang:\n')
            pending = {cf_id: pending[cf_id] for cf_id in hang_causes}

        if not hang_causes and pending:
            print(f'Cannot find a single root cause: hang CFs probably have {c("cyclic dependencies")}!\n')

    grouped_cfs: Dict[CallHistory, Tuple[int, List[AwaitedDF]]] = group_cfs(pending, cfs=cf_info)

    print_hang_report(
        grouped_cfs,
        dfs=df_info,
        cfs=cf_info,
        meta=meta
    )

    extra_count: int = initial_pending_count - len(pending)
    if extra_count:
        print(f'{c(extra_count)} more CFs never finished but had data dependencies on other hang CFs\n')


if __name__ == '__main__':
    main(sys.argv)
