from src.hello import *

from _pytest.monkeypatch import *

def test_hello(capfd):
    hello()
    out, err = capfd.readouterr()
    assert out == "hello!\n"
