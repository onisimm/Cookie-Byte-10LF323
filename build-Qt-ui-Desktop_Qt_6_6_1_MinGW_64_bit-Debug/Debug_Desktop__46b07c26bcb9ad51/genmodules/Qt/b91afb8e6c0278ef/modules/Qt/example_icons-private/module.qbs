import '../QtModule.qbs' as QtModule

QtModule {
    qtModuleName: "ExampleIcons"
    Depends { name: "Qt"; submodules: []}

    architectures: ["x86_64"]
    targetPlatform: "windows"
    hasLibrary: true
    staticLibsDebug: []
    staticLibsRelease: ["C:/Qt/6.6.1/mingw_64/lib/objects-RelWithDebInfo/ExampleIconsPrivate_resources_1/.rcc/qrc_example_icons.cpp.obj","C:/Qt/6.6.1/mingw_64/lib/libQt6ExampleIcons.a"]
    dynamicLibsDebug: []
    dynamicLibsRelease: []
    linkerFlagsDebug: []
    linkerFlagsRelease: []
    frameworksDebug: []
    frameworksRelease: []
    frameworkPathsDebug: []
    frameworkPathsRelease: []
    libNameForLinkerDebug: "Qt6ExampleIcons"
    libNameForLinkerRelease: "Qt6ExampleIcons"
    libFilePathDebug: undefined
    libFilePathRelease: "C:/Qt/6.6.1/mingw_64/lib/libQt6ExampleIcons.a"
    pluginTypes: []
    moduleConfig: ["static"]
    cpp.defines: ["QT_EXAMPLE_ICONS_LIB"]
    cpp.systemIncludePaths: ["C:/Qt/6.6.1/mingw_64/include","C:/Qt/6.6.1/mingw_64/include/QtExampleIcons","C:/Qt/6.6.1/mingw_64/include/QtExampleIcons/6.6.1","C:/Qt/6.6.1/mingw_64/include/QtExampleIcons/6.6.1/QtExampleIcons"]
    cpp.libraryPaths: []
    isStaticLibrary: true
    Group {
        files: [Qt["example_icons-private"].libFilePath]
        filesAreTargets: true
        fileTags: ["staticlibrary"]
    }
}
