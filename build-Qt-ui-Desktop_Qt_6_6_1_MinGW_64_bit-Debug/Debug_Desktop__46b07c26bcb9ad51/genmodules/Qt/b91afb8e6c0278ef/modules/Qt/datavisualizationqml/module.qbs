import '../QtModule.qbs' as QtModule

QtModule {
    qtModuleName: "DataVisualizationQml"
    Depends { name: "Qt"; submodules: []}

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
    libNameForLinkerDebug: "Qt6DataVisualizationQml"
    libNameForLinkerRelease: "Qt6DataVisualizationQml"
    libFilePathDebug: undefined
    libFilePathRelease: "C:/Qt/6.6.1/mingw_64/lib/libQt6DataVisualizationQml.a"
    pluginTypes: []
    moduleConfig: ["shared"]
    cpp.defines: ["QT_DATAVISUALIZATIONQML_LIB"]
    cpp.systemIncludePaths: ["C:/Qt/6.6.1/mingw_64/include","C:/Qt/6.6.1/mingw_64/include/QtDataVisualizationQml"]
    cpp.libraryPaths: []
    Group {
        files: [Qt["datavisualizationqml"].libFilePath]
        filesAreTargets: true
        fileTags: ["dynamiclibrary_import"]
    }
}
