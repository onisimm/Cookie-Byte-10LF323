import '../QtModule.qbs' as QtModule

QtModule {
    qtModuleName: "QmlTypeRegistrar"
    Depends { name: "Qt"; submodules: ["core"]}

    architectures: ["x86_64"]
    targetPlatform: "windows"
    hasLibrary: true
    staticLibsDebug: []
    staticLibsRelease: ["mpr","userenv"]
    dynamicLibsDebug: []
    dynamicLibsRelease: []
    linkerFlagsDebug: []
    linkerFlagsRelease: []
    frameworksDebug: []
    frameworksRelease: []
    frameworkPathsDebug: []
    frameworkPathsRelease: []
    libNameForLinkerDebug: "Qt6QmlTypeRegistrar"
    libNameForLinkerRelease: "Qt6QmlTypeRegistrar"
    libFilePathDebug: undefined
    libFilePathRelease: "C:/Qt/6.6.1/mingw_64/lib/libQt6QmlTypeRegistrar.a"
    pluginTypes: []
    moduleConfig: ["static"]
    cpp.defines: ["QT_QMLTYPEREGISTRAR_LIB"]
    cpp.systemIncludePaths: ["C:/Qt/6.6.1/mingw_64/include","C:/Qt/6.6.1/mingw_64/include/QtQmlTypeRegistrar","C:/Qt/6.6.1/mingw_64/include/QtQmlTypeRegistrar/6.6.1","C:/Qt/6.6.1/mingw_64/include/QtQmlTypeRegistrar/6.6.1/QtQmlTypeRegistrar"]
    cpp.libraryPaths: []
    isStaticLibrary: true
    Group {
        files: [Qt["qmltyperegistrar-private"].libFilePath]
        filesAreTargets: true
        fileTags: ["staticlibrary"]
    }
}
