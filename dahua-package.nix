{ pkgs ? import <nixpkgs> { } }:

let
  basename = "dahua";
  origin = "https://github.com/danny-mhlv/dahua-c-wrapper/releases/download/0.0.1";
in
with pkgs;
{
  "${basename}-avnetsdk" = pkgs.stdenv.mkDerivation rec {
    name = "libavnetsdk";

    src = fetchurl {
      url = "${origin}/${name}.so";
      hash = "sha256-4AZvhWJQZ+gd/Qa7jh9jIc7oVuRlcqNTofV8jLGzFzU=";
    };
    phases = [ "unpackPhase" "installPhase" ];
    unpackPhase = ":";
    installPhase = ''
      mkdir -p $out
      cp $src $out
    '';
  };

  "${basename}-dhnetsdk" = pkgs.stdenv.mkDerivation rec {
    name = "libdhnetsdk";

    src = fetchurl {
      url = "${origin}/${name}.so";
      hash = "sha256-tzXLd2Mv/HoouN/eSfnJGPUPywxRrPZgPTx5QkmWpUA=";
    };
    phases = [ "unpackPhase" "installPhase" ];
    unpackPhase = ":";
    installPhase = ''
      mkdir -p $out
      cp $src $out
    '';
  };

  "${basename}-dhconfigsdk" = pkgs.stdenv.mkDerivation rec {
    name = "libdhconfigsdk";

    src = fetchurl {
      url = "${origin}/${name}.so";
      hash = "sha256-MqqxXSlqeR/Vb6/Bo47ioR46kLDoLdWXiGbnd4lyx/0=";
    };
    phases = [ "unpackPhase" "installPhase" ];
    unpackPhase = ":";
    installPhase = ''
      mkdir -p $out
      cp $src $out
    '';
  };

  "${basename}-header-dhnetsdk" = pkgs.stdenv.mkDerivation rec {
    name = "dhnetsdk";

    src = fetchurl {
      url = "${origin}/${name}.h";
      hash = "sha256-YOCr8HppJtfIswGgL4HdbnM0CHzumjMP/ZQYT6BDdUA=";
    };
    phases = [ "unpackPhase" "installPhase" ];
    unpackPhase = ":";
    installPhase = ''
      mkdir -p $out
      cp $src $out
    '';
  };

  "${basename}-header-dhconfigsdk" = pkgs.stdenv.mkDerivation rec {
    name = "dhconfigsdk";

    src = fetchurl {
      url = "${origin}/${name}.h";
      hash = "sha256-hTRUtHwZTgEi29HmMq+71l1ub52O9JB4glCJ9sQDjvo=";
    };
    phases = [ "unpackPhase" "installPhase" ];
    unpackPhase = ":";
    installPhase = ''
      mkdir -p $out
      cp $src $out
    '';
  };
}
