.PHONY: commit
commit:
	python _fileHandler.py --overwrite --config-file _file_setting.json

.PHONY: commit-dryrun
commit-dryrun:
	python _fileHandler.py --dry-run