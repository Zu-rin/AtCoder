import os, re
from json import load
import argparse

from rich.console import Console
import git

class FileHandler:
    def __init__(self, config_file: str, overwrite: bool = False, dryrun: bool = False):
        self.console = Console()
        self.path  = os.getcwd()
        self.overwrite = overwrite
        self.dryrun = dryrun
        self.console.print("path = ", style="bold", end="", crop=False)
        self.console.print(self.path,  style="green")
        with open(config_file, "r") as f:
            self.config = load(f)
        self.files = [f for f in os.listdir(self.path) if os.path.isfile(os.path.join(self.path, f))]
        self.repo = git.Repo(self.path)


    def done(self):
        self.console.print("**Start**", style="bold blue")
        num = 0
        for file in self.files:
            match_key = None
            contest = {}
            for pattern in self.config.get("matching_pattern", {}):
                match_key = re.match(pattern, file)
                if match_key:
                    contest = self.config["matching_pattern"][pattern]
                    break
            if match_key:
                self.console.print("="*70)
                contest_dir = contest["dir"]
                subdir = ""
                if contest.get("subdir?"):
                    subdir = match_key.group(1)
                oldpath = os.path.join(self.path, file)
                newpath = os.path.join(self.path, contest_dir, subdir, file)
                self.__move_file(oldpath, newpath)
                num += 1
                self.commit(newpath)
        if num > 0:
            self.console.print(f"\nChanging names of {num} files is success!")
        else:
            self.console.print("\nNo files changed name.")
        self.console.print("**Finish**", style="bold blue")


    def __make_folders(self, path):
        if not self.dryrun:
            os.makedirs(path, exist_ok=True)
        self.console.print("Make directory ", end="", style="bold")
        self.console.print(path, style="green")


    def __move_file(self, oldpath, newpath):
        self.__make_folders(os.path.dirname(newpath))
        if os.path.exists(newpath):
            if not self.overwrite:
                self.console.print(newpath, style="red", end="")
                self.console.print("already exists. Skip this file.")
                return
            self.console.print(newpath, style="green", end="")
            self.console.print("already exists. Overwrite this file.")
            if not self.dryrun:
                os.remove(newpath)
        if not self.dryrun:
            os.rename(oldpath, newpath)
        self.console.print(oldpath, " [white]=>[/white] ", newpath, style="green")


    def commit(self, commit_file):
        fname = os.path.basename(commit_file)
        message = f"solved {fname}"
        author = f"{self.config['author']['name']} <{self.config['author']['email']}>"
        self.console.print("git commit  ", end="", style="yellow")
        self.console.print(f"{commit_file}", style="green")
        if self.dryrun:
            return
        self.repo.git.add(commit_file)
        self.repo.git.commit(commit_file, message=message, author=author)


def main():
    parser = argparse.ArgumentParser(description="File Handler")
    parser.add_argument("--config-file", type=str, help="Path to the rule JSON file", default="_file_setting.json")
    parser.add_argument("--overwrite", action="store_true", help="Overwrite existing files")
    parser.add_argument("--dry-run", action="store_true", help="Perform a dry run without making changes")
    args = parser.parse_args()

    file_handler = FileHandler(
        config_file=args.config_file,
        overwrite=args.overwrite,
        dryrun=args.dry_run
    )
    file_handler.done()


if __name__ == "__main__":
    main()
