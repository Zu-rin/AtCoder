.PHONY: commit
commit:
	python _fileHandler.py --target-dir "." --config-file _file_setting.json

.PHONY: dry-commit
dry-commit:
	python _fileHandler.py --target-dir "." --config-file _file_setting.json --dry-run