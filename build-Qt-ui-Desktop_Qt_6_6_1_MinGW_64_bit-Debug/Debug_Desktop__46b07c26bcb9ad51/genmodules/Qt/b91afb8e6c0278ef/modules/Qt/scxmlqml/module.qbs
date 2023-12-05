import '../QtModule.qbs' as QtModule

QtModule {
    qtModuleName: "ScxmlQml"
    Depends { name: "Qt"; submodules: ["core","qml","scxml"]}

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
    libNameForLinkerDebug: "Qt6ScxmlQml"
    libNameForLinkerRelease: "Qt6ScxmlQml"
    libFilePathDebug: undefined
    libFilePathRelease: "C:/Qt/6.6.1/mingw_64/lib/libQt6ScxmlQml.a"
    pluginTypes: []
    moduleConfig: ["shared"]
    cpp.defines: ["QT_SCXMLQML_LIB"]
    cpp.systemIncludePaths: ["C:/Qt/6.6.1/mingw_64/include","C:/Qt/6.6.1/mingw_64/include/QtScxmlQml"]
    cpp.libraryPaths: []
    Group {
        files: [Qt["scxmlqml"].libFilePath]
        filesAreTargets: true
        fileTags: ["dynamiclibrary_import"]
    }
}
