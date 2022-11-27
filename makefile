PY		= python3

test:
	$(PY) ./tests.py
	./main
	$(PY) ./plot.py