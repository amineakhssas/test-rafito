with import <nixpkgs> {};
stdenv.mkDerivation {
    name = "guess";
    src = ./.;
    nativeBuildInputs = [
        cmake
        catch2
        doxygen
    ];
    doCheck = true;
}

