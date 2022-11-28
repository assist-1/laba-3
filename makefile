PY		= python3

test:
	$(PY) ./tests.py
	./main --fromfile test.txt
	$(PY) ./plot.py

retry:
	./main --fromfile test.txt
	$(PY) ./plot.py