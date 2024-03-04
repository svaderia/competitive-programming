#!/usr/bin/env python3
# @author = svaderia
# date	  = 05/04/2020

import subprocess
import os
import sys

def get_string(name, count):
    return " * {} :   {}".format(name + " " * (12 - len(name)), count)

def get_table(name, count):
    return "|{} | {} |".format(name, count)

def main():
    args = sys.argv
    sol = (args[-1] == "solved")
    folders = ["CodeChef", "CodeForces", "SPOJ", "AtCoder", "Leetcode", "Other", "15195"]
    # if(sol) : folders.append("PEuler")
    base = "/Users/svaderia/Shyamal/GitHub/Competitive-Coding"
    readme_path = os.path.join(base, "README.md")

    count = [int(subprocess.check_output("find -E {} -regex '.*/*solution.(cpp|py)' | wc -l".format(os.path.join(base, f)), shell=True)) for f in folders]

    content = ""

    if(sol):
        content += "  \n".join([get_string(folders[x], count[x]) for x in range(len(folders))])
        content += "  \n{}".format(get_string("Total", sum(count)))
        print(content)
    else:
        with open(readme_path, "r") as f:
            content = f.read()

        content = content.split("# Competitive Coding\n")[0]
        content += "# Competitive Coding\n"
        content += "|Online Judge|Solved|\n"
        content += "|------ | ------|\n"
        content += "  \n".join([get_table(folders[x], count[x]) for x in range(len(folders))])
        content += "  \n{}".format(get_table("Total", sum(count)))
        with open(readme_path, "w") as f:
            f.write(content)

if __name__ == "__main__":
    main()
