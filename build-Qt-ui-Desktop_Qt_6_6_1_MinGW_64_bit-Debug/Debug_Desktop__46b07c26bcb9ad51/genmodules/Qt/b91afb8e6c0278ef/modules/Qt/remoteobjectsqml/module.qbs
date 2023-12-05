import '../QtModule.qbs' as QtModule

QtModule {
    qtModuleName: "RemoteObjectsQml"
    Depends { name: "Qt"; submodules: ["core","gui","qml","remoteobjects"]}

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
    libNameForLinkerDebug: "Qt6RemoteObjectsQml"
    libNameForLinkerRelease: "Qt6RemoteObjectsQml"
    libFilePathDebug: undefined
    libFilePathRelease: "C:/Qt/6.6.1/mingw_64/lib/libQt6RemoteObjectsQml.a"
    pluginTypes: []
    moduleConfig: ["shared"]
    cpp.defines: ["QT_REMOTEOBJECTSQML_LIB"]
    cpp.systemIncludePaths: ["C:/Qt/6.6.1/mingw_64/include","C:/Qt/6.6.1/mingw_64/include/QtRemoteObjectsQml"]
    cpp.libraryPaths: []
    Group {
        files: [Qt["remoteobjectsqml"].libFilePath]
        filesAreTargets: true
        fileTags: ["dynamiclibrary_import"]
    }
}
