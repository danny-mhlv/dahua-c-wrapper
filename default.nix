{ pkgs ? import <nixpkgs> { } }:

pkgs.llvmPackages_latest.stdenv.mkDerivation rec {
  pname = "dahua-wrapper";
  version = "1.0.0";

  src = ./.;

  nativeBuildInputs = with pkgs; [
    cmake
    (pkgs.callPackage ./dahua-package.nix { }).dahua-avnetsdk
    (pkgs.callPackage ./dahua-package.nix { }).dahua-dhnetsdk
    (pkgs.callPackage ./dahua-package.nix { }).dahua-dhconfigsdk
    (pkgs.callPackage ./dahua-package.nix { }).dahua-header-dhnetsdk.out
    (pkgs.callPackage ./dahua-package.nix { }).dahua-header-dhconfigsdk.out
  ];
  buildInputs = with pkgs; [
    cmake
    clang
    (pkgs.callPackage ./dahua-package.nix { }).dahua-avnetsdk
    (pkgs.callPackage ./dahua-package.nix { }).dahua-dhnetsdk
    (pkgs.callPackage ./dahua-package.nix { }).dahua-dhconfigsdk
    (pkgs.callPackage ./dahua-package.nix { }).dahua-header-dhnetsdk.out
    (pkgs.callPackage ./dahua-package.nix { }).dahua-header-dhconfigsdk.out
  ];

  cmakeFlags = [
    "-DDAHUA_NET_SDK=${(pkgs.callPackage ./dahua-package.nix { }).dahua-dhnetsdk.out}/libdhnetsdk.so"
    "-DDAHUA_CONFIG_SDK=${(pkgs.callPackage ./dahua-package.nix { }).dahua-dhconfigsdk.out}/libdhconfigsdk.so"
    "-DDAHUA_INC_PATH=${(pkgs.callPackage ./dahua-package.nix { }).dahua-header-dhconfigsdk.out};${(pkgs.callPackage ./dahua-package.nix { }).dahua-header-dhnetsdk.out}"
    "-DCMAKE_INSTALL_INCLUDEDIR=${(pkgs.callPackage ./dahua-package.nix { }).dahua-header-dhconfigsdk.out};${(pkgs.callPackage ./dahua-package.nix { }).dahua-header-dhnetsdk.out}"
  ];
}
