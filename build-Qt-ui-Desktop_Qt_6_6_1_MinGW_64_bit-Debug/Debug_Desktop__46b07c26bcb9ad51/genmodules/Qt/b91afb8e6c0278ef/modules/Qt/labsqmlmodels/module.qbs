import '../QtModule.qbs' as QtModule

QtModule {
    qtModuleName: "LabsQmlModels"
    Depends { name: "Qt"; submodules: ["qmlmodels-private","qml-private"]}

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
    libNameForLinkerDebug: "Qt6LabsQmlModels"
    libNameForLinkerRelease: "Qt6LabsQmlModels"
    libFilePathDebug: undefined
    libFilePathRelease: "C:/Qt/6.6.1/mingw_64/lib/libQt6LabsQmlModels.a"
    pluginTypes: []
    moduleConfig: ["shared"]
    cpp.defines: ["QT_LABSQMLMODELS_LIB"]
    cpp.systemIncludePaths: ["C:/Qt/6.6.1/mingw_64/include","C:/Qt/6.6.1/mingw_64/include/QtLabsQmlModels"]
    cpp.libraryPaths: []
    Group {
        files: [Qt["labsqmlmodels"].libFilePath]
        filesAreTargets: true
        fileTags: ["dynamiclibrary_import"]
    }
}
