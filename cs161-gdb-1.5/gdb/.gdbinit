echo Setting up the environment for debugging gdb.\n

set complaints 1

b internal_error

b info_command
commands
	silent
	return
end

dir /home/blakedonzac/cs161/cs161-gdb-1.5/./gdb-6.6+cs161/gdb/../libiberty
dir /home/blakedonzac/cs161/cs161-gdb-1.5/./gdb-6.6+cs161/gdb/../bfd
dir /home/blakedonzac/cs161/cs161-gdb-1.5/./gdb-6.6+cs161/gdb
dir .
set prompt (top-gdb) 
