# Sneak command

Detach a process from the current tty, run it in background. This command will run every command you give it as argument in background, so the process will continue even after you closed your tty. This is similar to the ```nohup``` command.

### Compile
On MacOS & Linux:  
```gcc bg.c -o sneak```

### Run

```$ ./sneak <command> [arguments]```

Process output will be written in a file ```bg_output.log```, change it in source code.
