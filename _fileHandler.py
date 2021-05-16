import os, re
from rich import print
from rich.console import Console

def main():
    console = Console()

    path  = os.getcwd()
    console.print("[bold]path[/bold] = ", end = "")
    console.print(path,  style="green")
    files = [f for f in os.listdir(path) if os.path.isfile(os.path.join(path, f))]

    num = 0
    for f in files:
        if re.match(r"^(AGC|ARC|ABC)", f) != None:
            oldpath = os.path.join(path, f)
            if f[:3] == "ABC":
                newdir = os.path.join(path, "AtCoder_Beginner_Contest", f[:6])
                newpath = os.path.join(newdir, f)
            elif f[:3] == "ARC":
                newdir = os.path.join(path, "AtCoder_Regular_Contest", f[:6])
                newpath = os.path.join(newdir, f)
            elif f[:3] == "AGC":
                newdir = os.path.join(path, "AtCoder_Grand_Contest", f[:6])
                newpath = os.path.join(path, "AtCoder_Grand_Contest", f[:6], f)
            try:
                os.rename(oldpath, newpath)
            except FileExistsError:
                console.print(str(os.path.basename), style="green", ans="")
                console.print(" already exists. Overwrite this file.")
                os.remove(newpath)
                os.rename(oldpath, newpath)
            except FileNotFoundError:
                console.print("Make directry ", end="")
                console.print(newdir, style="green")
                os.mkdir(newdir)
                os.rename(oldpath, newpath)
            console.print(oldpath, " [white]=>[/white] ", newpath, style="green")
            num += 1

    if num > 0:
        console.print("Changing names of " + str(num) + " files is success!")
    else:
        console.print("No files changed name.")

if __name__ == "__main__":
    print("[bold blue]**Start**[/bold blue]")
    main()
    print("[bold blue]**Finish**[/bold blue]")
