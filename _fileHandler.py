import os, re
from json import load
from rich import print
from rich.console import Console

def search_contest(fname: str, rules: dict):
    for key in rules:
        if len(key) < len(fname) and fname[:len(key)] == key:
            return key
    return None

def make_folder(path, console):
    try:
        os.mkdir(path)
        console.print("Make directry ", end="", style="bold")
        console.print(path, style="green")
    except FileExistsError:
        pass

def main():
    console = Console()
    path  = os.getcwd()
    console.print("[bold]path[/bold] = ", end = "")
    console.print(path,  style="green")

    with open("_file_setting.json", "r") as f:
        rules = load(f)
    files = [f for f in os.listdir(path) if os.path.isfile(os.path.join(path, f))]

    num = 0
    for f in files:
        fname, fext = os.path.splitext(f)
        match_key = search_contest(fname, rules)
        if match_key:
            console.print("="*70)
            contest = rules[match_key]
            contest_dir = contest["dir"]
            subdir = ""
            if contest.get("subdir?"):
                subdir = fname[:fname.find("-")] if "-" in fname else fname[:-1]

            oldpath = os.path.join(path, f)
            make_folder(os.path.join(path, contest_dir), console)
            make_folder(os.path.join(path, contest_dir, subdir), console)
            newpath = os.path.join(path, contest_dir, subdir, f)
            try:
                os.rename(oldpath, newpath)
            except FileExistsError:
                console.print(newpath, style="green", end="")
                console.print(" already exists. Overwrite this file.")
                os.remove(newpath)
                os.rename(oldpath, newpath)
            console.print(oldpath, " [white]=>[/white] ", newpath, style="green")
            num += 1

    if num > 0:
        console.print("\nChanging names of " + str(num) + " files is success!")
    else:
        console.print("\nNo files changed name.")

if __name__ == "__main__":
    print("[bold blue]**Start**[/bold blue]")
    main()
    print("[bold blue]**Finish**[/bold blue]")
