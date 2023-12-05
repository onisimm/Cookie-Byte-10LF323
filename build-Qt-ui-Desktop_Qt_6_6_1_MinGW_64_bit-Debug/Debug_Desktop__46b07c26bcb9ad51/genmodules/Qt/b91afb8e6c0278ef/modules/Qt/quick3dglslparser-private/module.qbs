import '../QtModule.qbs' as QtModule

QtModule {
    qtModuleName: "Quick3DGlslParser"
    Depends { name: "Qt"; submodules: ["core"]}

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
    libNameForLinkerDebug: "Qt6Quick3DGlslParser"
    libNameForLinkerRelease: "Qt6Quick3DGlslParser"
    libFilePathDebug: undefined
    libFilePathRelease: "C:/Qt/6.6.1/mingw_64/lib/libQt6Quick3DGlslParser.a"
    pluginTypes: []
    moduleConfig: ["shared"]
    cpp.defines: ["QT_QUICK3DGLSLPARSER_LIB"]
    cpp.systemIncludePaths: ["C:/Qt/6.6.1/mingw_64/include","C:/Qt/6.6.1/mingw_64/include/QtQuick3DGlslParser","C:/Qt/6.6.1/mingw_64/include/QtQuick3DGlslParser/6.6.1","C:/Qt/6.6.1/mingw_64/include/QtQuick3DGlslParser/6.6.1/QtQuick3DGlslParser"]
    cpp.libraryPaths: []
    Group {
        files: [Qt["quick3dglslparser-private"].libFilePath]
        filesAreTargets: true
        fileTags: ["dynamiclibrary_import"]
    }
}
