from functools import reduce
from itertools import chain

import yaml


with open("./opcodes.yml", "r") as fobj:
    d = dict(yaml.load(fobj.read(), yaml.SafeLoader))
    assert (
        len(
            reduce(
                lambda a, x: a | x,
                map(set, chain(*[cpu.values() for cpu in d.values()])),
                set(),
            )
        )
        == 16
    )
