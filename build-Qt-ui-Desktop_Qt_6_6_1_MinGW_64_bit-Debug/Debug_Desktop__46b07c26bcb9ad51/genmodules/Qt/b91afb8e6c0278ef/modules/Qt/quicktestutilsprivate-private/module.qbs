import '../QtModule.qbs' as QtModule

QtModule {
    qtModuleName: "QuickTestUtils"
    Depends { name: "Qt"; submodules: ["core","testlib","network","qml","qml-private"]}

    architectures: ["x86_64"]
    targetPlatform: "windows"
    hasLibrary: true
    staticLibsDebug: []
    staticLibsRelease: ["user32","d3d11","dxgi","dxguid","d3d12","ws2_32","shell32","mpr","userenv"]
    dynamicLibsDebug: []
    dynamicLibsRelease: []
    linkerFlagsDebug: []
    linkerFlagsRelease: []
    frameworksDebug: []
    frameworksRelease: []
    frameworkPathsDebug: []
    frameworkPathsRelease: []
    libNameForLinkerDebug: "Qt6QuickTestUtils"
    libNameForLinkerRelease: "Qt6QuickTestUtils"
    libFilePathDebug: undefined
    libFilePathRelease: "C:/Qt/6.6.1/mingw_64/lib/libQt6QuickTestUtils.a"
    pluginTypes: []
    moduleConfig: ["static"]
    cpp.defines: ["QT_QUICKTESTUTILSPRIVATE_LIB"]
    cpp.systemIncludePaths: ["C:/Qt/6.6.1/mingw_64/include","C:/Qt/6.6.1/mingw_64/include/QtQuickTestUtils","C:/Qt/6.6.1/mingw_64/include/QtQuickTestUtils/6.6.1","C:/Qt/6.6.1/mingw_64/include/QtQuickTestUtils/6.6.1/QtQuickTestUtils"]
    cpp.libraryPaths: []
    isStaticLibrary: true
    Group {
        files: [Qt["quicktestutilsprivate-private"].libFilePath]
        filesAreTargets: true
        fileTags: ["staticlibrary"]
    }
}
