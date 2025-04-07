#! /usr/bin/python3

import argparse
import json
import os
from typing import Iterator

def get_data_files(
    whitelist: list[str] | None = None,
    blacklist: list[str] | None = None,
) -> Iterator[str]:
    script_dir = os.path.dirname(os.path.abspath(__file__))
    root_dir = os.path.dirname(script_dir)
    data_dir = os.path.join(root_dir, 'data')

    for (path, _, filenames) in os.walk(data_dir):
        for filename in filenames:

            if whitelist is not None:
                accepted = False
                for term in whitelist:
                    if term in filename:
                        accepted = True
                if not accepted:
                    continue

            if blacklist is not None:
                blocked = False
                for term in blacklist:
                    if term in filename:
                        blocked = True
                if blocked:
                    continue

            yield os.path.join(path, filename)

def main():

    files = [*get_data_files(
        whitelist=None,
        blacklist=['changelog.json', 'README.md']
    )]

    print(f"Viewing files:", *[f"    {file}" for file in files], sep='\n')

    merged = {}
    for filename in files:
        with open(filename) as file:
            try:
                data = json.load(file)
                merged = {**merged, **data}

            except Exception as e:
                print(f"Error handling file: {filename}")
                print(e)

    with open("output.json", "w") as output:
        json.dump(merged, output, indent=2)

if __name__ == "__main__":
    main()