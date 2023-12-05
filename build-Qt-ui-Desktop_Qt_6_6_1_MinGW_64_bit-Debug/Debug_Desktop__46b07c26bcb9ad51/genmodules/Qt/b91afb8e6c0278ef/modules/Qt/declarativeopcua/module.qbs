import '../QtModule.qbs' as QtModule

QtModule {
    qtModuleName: "DeclarativeOpcua"
    Depends { name: "Qt"; submodules: ["core","gui","opcua","quick"]}

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
    libNameForLinkerDebug: "Qt6DeclarativeOpcua"
    libNameForLinkerRelease: "Qt6DeclarativeOpcua"
    libFilePathDebug: undefined
    libFilePathRelease: "C:/Qt/6.6.1/mingw_64/lib/libQt6DeclarativeOpcua.a"
    pluginTypes: []
    moduleConfig: ["shared"]
    cpp.defines: ["QT_DECLARATIVEOPCUA_LIB"]
    cpp.systemIncludePaths: ["C:/Qt/6.6.1/mingw_64/include","C:/Qt/6.6.1/mingw_64/include/QtDeclarativeOpcua"]
    cpp.libraryPaths: []
    Group {
        files: [Qt["declarativeopcua"].libFilePath]
        filesAreTargets: true
        fileTags: ["dynamiclibrary_import"]
    }
}
