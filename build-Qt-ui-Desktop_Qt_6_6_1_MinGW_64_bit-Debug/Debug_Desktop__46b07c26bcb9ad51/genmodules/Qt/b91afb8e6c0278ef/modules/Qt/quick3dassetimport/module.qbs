import '../QtModule.qbs' as QtModule

QtModule {
    qtModuleName: "Quick3DAssetImport"
    Depends { name: "Qt"; submodules: ["core","gui","qml","quick3dutils"]}

    architectures: ["x86_64"]
    targetPlatform: "windows"
    hasLibrary: true
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
    libNameForLinkerDebug: "Qt6Quick3DAssetImport"
    libNameForLinkerRelease: "Qt6Quick3DAssetImport"
    libFilePathDebug: undefined
    libFilePathRelease: "C:/Qt/6.6.1/mingw_64/lib/libQt6Quick3DAssetImport.a"
    pluginTypes: ["assetimporters"]
    moduleConfig: ["shared"]
    cpp.defines: ["QT_QUICK3DASSETIMPORT_LIB"]
    cpp.systemIncludePaths: ["C:/Qt/6.6.1/mingw_64/include","C:/Qt/6.6.1/mingw_64/include/QtQuick3DAssetImport"]
    cpp.libraryPaths: []
    Group {
        files: [Qt["quick3dassetimport"].libFilePath]
        filesAreTargets: true
        fileTags: ["dynamiclibrary_import"]
    }
}
