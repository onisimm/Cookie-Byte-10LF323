import '../QtModule.qbs' as QtModule

QtModule {
    qtModuleName: "Quick3DUtils"
    Depends { name: "Qt"; submodules: ["core","gui"]}

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
    libNameForLinkerDebug: "Qt6Quick3DUtils"
    libNameForLinkerRelease: "Qt6Quick3DUtils"
    libFilePathDebug: undefined
    libFilePathRelease: "C:/Qt/6.6.1/mingw_64/lib/libQt6Quick3DUtils.a"
    pluginTypes: []
    moduleConfig: ["shared"]
    cpp.defines: ["QT_QUICK3DUTILS_LIB"]
    cpp.systemIncludePaths: ["C:/Qt/6.6.1/mingw_64/include","C:/Qt/6.6.1/mingw_64/include/QtQuick3DUtils"]
    cpp.libraryPaths: []
    Group {
        files: [Qt["quick3dutils"].libFilePath]
        filesAreTargets: true
        fileTags: ["dynamiclibrary_import"]
    }
}
