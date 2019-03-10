#include <windows.h>
#include <tchar.h>
#include <stdio.h>
using namespace std;


int main()
{
    const TCHAR batchFilePath[MAX_PATH] = _T("Enter bat file Path \\remover.bat");

    TCHAR systemDirPath[MAX_PATH] = _T("");
    GetSystemDirectory( systemDirPath, sizeof(systemDirPath)/sizeof(_TCHAR) );

    // path to cmd.exe, path to batch file, plus some space for quotes, spaces, etc.
    TCHAR commandLine[2 * MAX_PATH + 16] = _T("");

    _sntprintf( commandLine, sizeof(commandLine)/sizeof(_TCHAR),
        _T("\"%s\\cmd.exe\" /C \"%s\""), systemDirPath, batchFilePath );

    STARTUPINFO si = {0}; // alternative way to zero array
    si.cb = sizeof(si);
    PROCESS_INFORMATION pi = {0};

    if( !CreateProcess( NULL,
        commandLine,
        NULL,
        NULL,
        FALSE,
        0,
        NULL,
        NULL,
        &si,
        &pi )
        )
    {
        _tprintf( _T("CreateProcess failed (%d)\n"), GetLastError() );
        return FALSE;
    }

    WaitForSingleObject( pi.hProcess, INFINITE );
    CloseHandle( pi.hProcess );
    CloseHandle( pi.hThread );

    return 0;
}
