import json
from typing import List, Tuple, Dict

from dtypes import Id, DFInfo, CF, AwaitedDF, CodeMetaInformation


def load_cf_info(files: List[str]) -> Dict[Id, CF]:
    result: Dict[Id, CF] = {}

    def load_cf_(entry: str) -> Tuple[Id, CF]:
        cf_dict = json.loads(entry)

        return (
            tuple(cf_dict['id']),
            CF(
                input=set(map(tuple, cf_dict.get('i', []))),
                output=set(map(tuple, cf_dict.get('o', []))),
                history=cf_dict['h'],
                block=cf_dict['h'][-1]
            )
        )

    for file_name in files:
        with open(file_name, 'rt') as file:
            result.update({
                id_: cf for id_, cf in map(load_cf_, file.readlines())
            })

    return result


def load_pending(files: List[str]) -> Dict[Id, List[AwaitedDF]]:
    result: Dict[Id, List[AwaitedDF]] = {}

    def to_awaited_df_(entry: dict) -> AwaitedDF:
        expression = entry['n']
        name_end_index = expression.find('[')
        indices_count = expression.count('[')
        local_name = expression[:name_end_index] if name_end_index > 0 else expression
        
        return AwaitedDF(
            idx=tuple(entry['i']),
            local_name=local_name,
            indices_count=int(indices_count),
            expression=expression
        )

    def load_pending_(entry: str) -> Tuple[Id, List[AwaitedDF]]:
        pending = json.loads(entry)

        return (
            tuple(pending['id']),
            list(map(to_awaited_df_, pending.get('w', [])))
        )

    for file_name in files:
        with open(file_name, 'rt') as file:
            result.update({
                id_: awaited for id_, awaited in map(load_pending_, file.readlines())
            })

    return result


def load_id_map(files: List[str]) -> Dict[Id, DFInfo]:
    result: Dict[Id, DFInfo] = {}

    def load_df_info_(id_map_entry: str) -> Tuple[Id, str, int]:
        id_, df = id_map_entry.split('>')

        idx_ = tuple(map(int, id_.split()))
        name_, block_ = df.split()

        return idx_, name_, int(block_)

    for file_name in files:
        with open(file_name, 'rt') as file:
            result.update({
                idx: DFInfo(name, block) for idx, name, block in map(load_df_info_, file.readlines())
            })

    return result


TI_FILE: str = 'build/preprocessed.fa.ti'
BLOCKS_INFO_FILE: str = 'build/cpp_blocks_info.json'


def load_meta_info() -> CodeMetaInformation:
    try:
        with open(TI_FILE, 'r') as file:
            ti = json.load(file)

        with open(BLOCKS_INFO_FILE, 'r') as file:
            blocks_info = json.load(file)

        return CodeMetaInformation(blocks_info, ti)
    except FileNotFoundError:
        print(
            f'Build files ({TI_FILE}, {BLOCKS_INFO_FILE}) not found where expected. '
            f'Please ensure you build your program with --no-cleanup and --build-dir=build'
        )
        exit(1)
