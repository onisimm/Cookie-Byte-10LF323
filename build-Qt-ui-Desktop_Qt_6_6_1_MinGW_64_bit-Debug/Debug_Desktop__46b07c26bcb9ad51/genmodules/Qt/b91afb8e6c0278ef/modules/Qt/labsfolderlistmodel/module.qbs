import '../QtModule.qbs' as QtModule

QtModule {
    qtModuleName: "LabsFolderListModel"
    Depends { name: "Qt"; submodules: ["core-private","qml-private","qmlmodels-private"]}

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
    libNameForLinkerDebug: "Qt6LabsFolderListModel"
    libNameForLinkerRelease: "Qt6LabsFolderListModel"
    libFilePathDebug: undefined
    libFilePathRelease: "C:/Qt/6.6.1/mingw_64/lib/libQt6LabsFolderListModel.a"
    pluginTypes: []
    moduleConfig: ["shared"]
    cpp.defines: ["QT_LABSFOLDERLISTMODEL_LIB"]
    cpp.systemIncludePaths: ["C:/Qt/6.6.1/mingw_64/include","C:/Qt/6.6.1/mingw_64/include/QtLabsFolderListModel"]
    cpp.libraryPaths: []
    Group {
        files: [Qt["labsfolderlistmodel"].libFilePath]
        filesAreTargets: true
        fileTags: ["dynamiclibrary_import"]
    }
}
