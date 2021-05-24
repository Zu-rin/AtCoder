import os, re
from json import load

from rich import print
from rich.console import Console
import git

class FileHandler:
    def __init__(self, rulepath: str):
        self.console = Console()
        self.path  = os.getcwd()
        self.console.print("[bold]path[/bold] = ", end = "")
        self.console.print(self.path,  style="green")
        with open(rulepath, "r") as f:
            self.rules = load(f)
        self.files = [f for f in os.listdir(self.path) if os.path.isfile(os.path.join(self.path, f))]
        self.repo = git.Repo(self.path)
    
    def done(self):
        num = 0
        for f in self.files:
            fname, fext = os.path.splitext(f)
            match_key = self.search_contest(fname)
            if match_key:
                self.console.print("="*70)
                contest = self.rules[match_key]
                contest_dir = contest["dir"]
                subdir = ""
                if contest.get("subdir?"):
                    subdir = fname[:fname.find("-")] if "-" in fname else fname[:-1]

                oldpath = os.path.join(self.path, f)
                self.make_folder(os.path.join(self.path, contest_dir))
                self.make_folder(os.path.join(self.path, contest_dir, subdir))
                newpath = os.path.join(self.path, contest_dir, subdir, f)
                try:
                    os.rename(oldpath, newpath)
                except FileExistsError:
                    self.console.print(newpath, style="green", end="")
                    self.console.print(" already exists. Overwrite this file.")
                    os.remove(newpath)
                    os.rename(oldpath, newpath)
                self.console.print(oldpath, " [white]=>[/white] ", newpath, style="green")
                num += 1
                self.commit(newpath)

        if num > 0:
            self.console.print(f"\nChanging names of {num} files is success!")
            self.push_all()
        else:
            self.console.print("\nNo files changed name.")

    def search_contest(self, fname: str):
        for key in self.rules:
            if len(key) < len(fname) and fname[:len(key)] == key:
                return key
        return None

    def make_folder(self, path):
        try:
            os.mkdir(path)
            self.console.print("Make directory ", end="", style="bold")
            self.console.print(path, style="green")
        except FileExistsError:
            pass
    
    def commit(self, commit_file):
        dir, fname = os.path.split(commit_file)
        fname, fext = os.path.splitext(fname)
        message = f"solved {fname}"
        self.console.print("git commit  ", end="", style="yellow")
        self.console.print(f"{commit_file}", style="green")
        self.repo.git.add(commit_file)
        self.repo.git.commit(commit_file, message=message, author="Zu-rin <s165810t@gmail.com>")
    
    def push_all(self):
        self.console.print("git pushing  ", end="", style="magenta bold")
        self.console.print("HEAD/master => origin/master")
        self.repo.git.push('origin', 'master')

if __name__ == "__main__":
    print("[bold blue]**Start**[/bold blue]")
    file_handler = FileHandler("_file_setting.json")
    file_handler.done()
    print("[bold blue]**Finish**[/bold blue]")
