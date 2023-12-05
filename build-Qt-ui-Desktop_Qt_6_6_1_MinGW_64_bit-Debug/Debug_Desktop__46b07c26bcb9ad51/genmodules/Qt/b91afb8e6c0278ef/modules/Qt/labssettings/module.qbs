import '../QtModule.qbs' as QtModule

QtModule {
    qtModuleName: "LabsSettings"
    Depends { name: "Qt"; submodules: ["core","qml"]}

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
    libNameForLinkerDebug: "Qt6LabsSettings"
    libNameForLinkerRelease: "Qt6LabsSettings"
    libFilePathDebug: undefined
    libFilePathRelease: "C:/Qt/6.6.1/mingw_64/lib/libQt6LabsSettings.a"
    pluginTypes: []
    moduleConfig: ["shared"]
    cpp.defines: ["QT_LABSSETTINGS_LIB"]
    cpp.systemIncludePaths: ["C:/Qt/6.6.1/mingw_64/include","C:/Qt/6.6.1/mingw_64/include/QtLabsSettings"]
    cpp.libraryPaths: []
    Group {
        files: [Qt["labssettings"].libFilePath]
        filesAreTargets: true
        fileTags: ["dynamiclibrary_import"]
    }
}
