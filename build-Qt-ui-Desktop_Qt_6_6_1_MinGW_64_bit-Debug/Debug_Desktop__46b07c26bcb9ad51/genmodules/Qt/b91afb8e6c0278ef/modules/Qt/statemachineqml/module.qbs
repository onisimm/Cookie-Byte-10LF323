import '../QtModule.qbs' as QtModule

QtModule {
    qtModuleName: "StateMachineQml"
    Depends { name: "Qt"; submodules: ["core","qml","statemachine"]}

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
    libNameForLinkerDebug: "Qt6StateMachineQml"
    libNameForLinkerRelease: "Qt6StateMachineQml"
    libFilePathDebug: undefined
    libFilePathRelease: "C:/Qt/6.6.1/mingw_64/lib/libQt6StateMachineQml.a"
    pluginTypes: []
    moduleConfig: ["shared"]
    cpp.defines: ["QT_STATEMACHINEQML_LIB"]
    cpp.systemIncludePaths: ["C:/Qt/6.6.1/mingw_64/include","C:/Qt/6.6.1/mingw_64/include/QtStateMachineQml"]
    cpp.libraryPaths: []
    Group {
        files: [Qt["statemachineqml"].libFilePath]
        filesAreTargets: true
        fileTags: ["dynamiclibrary_import"]
    }
}
