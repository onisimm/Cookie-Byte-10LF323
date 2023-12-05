import '../QtModule.qbs' as QtModule

QtModule {
    qtModuleName: "QuickControlsTestUtils"
    Depends { name: "Qt"; submodules: ["core","testlib","qml","qml-private","quick","quickcontrols2","quickdialogs2quickimpl-private","quick-private","quicktemplates2","quicktemplates2-private","quicktestutilsprivate-private"]}

    architectures: ["x86_64"]
    targetPlatform: "windows"
    hasLibrary: true
    staticLibsDebug: []
    staticLibsRelease: ["C:/Qt/6.6.1/mingw_64/qml/Qt/test/controls/objects-RelWithDebInfo/QuickControlsTestUtilsPrivate_resources_1/.rcc/qrc_qmake_Qt_test_controls.cpp.obj"]
    dynamicLibsDebug: []
    dynamicLibsRelease: []
    linkerFlagsDebug: []
    linkerFlagsRelease: []
    frameworksDebug: []
    frameworksRelease: []
    frameworkPathsDebug: []
    frameworkPathsRelease: []
    libNameForLinkerDebug: "Qt6QuickControlsTestUtils"
    libNameForLinkerRelease: "Qt6QuickControlsTestUtils"
    libFilePathDebug: undefined
    libFilePathRelease: "C:/Qt/6.6.1/mingw_64/lib/libQt6QuickControlsTestUtils.a"
    pluginTypes: []
    moduleConfig: ["static"]
    cpp.defines: ["QT_QUICKCONTROLSTESTUTILSPRIVATE_LIB"]
    cpp.systemIncludePaths: ["C:/Qt/6.6.1/mingw_64/include","C:/Qt/6.6.1/mingw_64/include/QtQuickControlsTestUtils","C:/Qt/6.6.1/mingw_64/include/QtQuickControlsTestUtils/6.6.1","C:/Qt/6.6.1/mingw_64/include/QtQuickControlsTestUtils/6.6.1/QtQuickControlsTestUtils"]
    cpp.libraryPaths: []
    isStaticLibrary: true
    Group {
        files: [Qt["quickcontrolstestutilsprivate-private"].libFilePath]
        filesAreTargets: true
        fileTags: ["staticlibrary"]
    }
}
