{ pkgs }: {
	deps = [
		pkgs.valgrind
  pkgs.python38Packages.pwntools
  pkgs.clang_12
		pkgs.ccls
		pkgs.gdb
		pkgs.gnumake
	];
}