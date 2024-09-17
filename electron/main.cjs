const { log } = require('console')
const { app, BrowserWindow, ipcMain } = require('electron');
const path = require('path')

if (require('electron-squirrel-startup')) app.quit();

const isDevEnvironment = process.env.DEV_ENV === 'true'

// enable live reload for electron in dev mode
if (isDevEnvironment) {
    require('electron-reload')(__dirname, {
        electron: path.join(__dirname, '..', 'node_modules', '.bin', 'electron'),
        hardResetMethod: 'exit'
    });
}

let mainWindow;

const createWindow = () => {
    
    mainWindow = new BrowserWindow({
        minWidth: 1280,
        minHeight: 720,
        webPreferences: {
            preload: path.join(__dirname, 'preload.js')
        }
    })
    mainWindow.menuBarVisible = false;

    if (isDevEnvironment) {
        mainWindow.loadURL('http://localhost:5173/');
        log('Running in dev mode.')
    }

    else {
        // when not in dev mode, load the build file instead
        mainWindow.loadFile(path.join(__dirname, 'build', 'index.html'));
        log('Running in prod mode.')
    }
}

app.on('ready', () => {
    ipcMain.handle("saveDB", () => {
        log(`saving db!`);
    });
    createWindow();
});

app.on('activate', () => {
    if (BrowserWindow.getAllWindows().length === 0) createWindow()
})

app.on('window-all-closed', () => {
    if (process.platform !== 'darwin') app.quit()
})
