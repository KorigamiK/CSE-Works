# VHDL workflow

Installation? check [INSTALL.md](INSTALL.md)

Create your VHDL file, and it's test bench,
then run the following command.

```bash
make I=<input_file> T=<test_bench_file> E=<test_bench_entity_name>
```

Example:

```bash
make I=test/counter.vhdl T=test/counter.test.vhdl E=counter_tb
```

This will generate wave and `vcd` files to the `waves` directory.

Then open generated `.ghw` or `.vcd` file with `GTKwave`.

## Options

To change simulation time pass `S_TIME = <time>` to make command.
Time can be in `ns`, `us`, and `ms`.

Example:

```bash
make I=test/counter.vhdl T=test/counter.test.vhdl E=counter_tb S_TIME=1ms
```
