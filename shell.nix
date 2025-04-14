{ pkgs ? import <nixpkgs> {} }:

pkgs.mkShell {
  buildInputs = [
    pkgs.gcc
  ];

  shellHook = ''
    zsh
  '';
}
