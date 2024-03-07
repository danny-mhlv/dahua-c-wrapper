{
  description = "DahuaWrapper Flake";

  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-unstable";
  };

  outputs = { self, nixpkgs }:
    let
      system = "x86_64-linux";
      pkgs = nixpkgs.legacyPackages.${system};
    in
    {
      packages.${system}.default = (pkgs.callPackage ./default.nix { inherit pkgs; });
      devShells.${system}.default = pkgs.mkShell {
        packages = with pkgs;
          [
            cmake
            gnumake
            libgcc
            gcc13
            gdb
            clang-tools
            llvmPackages_latest.lldb
            llvmPackages_latest.libstdcxxClang
            llvmPackages_latest.libcxx
            valgrind
          ];

        buildInputs = with pkgs; [
          (pkgs.callPackage ./dahua-package.nix { }).dahua-avnetsdk
          (pkgs.callPackage ./dahua-package.nix { }).dahua-dhnetsdk
          (pkgs.callPackage ./dahua-package.nix { }).dahua-dhconfigsdk
          (pkgs.callPackage ./dahua-package.nix { }).dahua-header-dhnetsdk
          (pkgs.callPackage ./dahua-package.nix { }).dahua-header-dhconfigsdk
        ];

        shellHook =
          let
            icon = "f121";
          in
          ''
            export PS1="$(echo -e '\u${icon}') {\[$(tput sgr0)\]\[\033[38;5;228m\]\w\[$(tput sgr0)\]\[\033[38;5;15m\]} (dahua-wrapper-sh) \\$ \[$(tput sgr0)\]"
          '';
      };
    };
}
