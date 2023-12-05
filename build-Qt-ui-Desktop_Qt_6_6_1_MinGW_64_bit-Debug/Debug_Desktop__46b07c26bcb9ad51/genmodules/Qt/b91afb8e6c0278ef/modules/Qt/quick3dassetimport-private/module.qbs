import '../QtModule.qbs' as QtModule

QtModule {
    qtModuleName: "Quick3DAssetImport"
    Depends { name: "Qt"; submodules: ["core-private","quick3dutils-private","quick3dassetimport"]}

    architectures: ["x86_64"]
    targetPlatform: "windows"
    hasLibrary: false
    staticLibsDebug: []
    staticLibsRelease: []
    dynamicLibsDebug: []
    dynamicLibsRelease: []
    linkerFlagsDebug: []
    linkerFlagsRelease: []
    frameworksDebug: []
    frameworksRelease: []
    frameworkPathsDebug: []
    frameworkPathsRelease: []
    libNameForLinkerDebug: undefined
    libNameForLinkerRelease: undefined
    libFilePathDebug: undefined
    libFilePathRelease: undefined
    pluginTypes: []
    moduleConfig: []
    cpp.defines: []
    cpp.systemIncludePaths: ["C:/Qt/6.6.1/mingw_64/include/QtQuick3DAssetImport/6.6.1","C:/Qt/6.6.1/mingw_64/include/QtQuick3DAssetImport/6.6.1/QtQuick3DAssetImport"]
    cpp.libraryPaths: []
    
}
