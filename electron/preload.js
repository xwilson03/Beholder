const { contextBridge, ipcRenderer } = require('electron')

const api = {
    saveDB: () => ipcRenderer.invoke("saveDB")
}

contextBridge.exposeInMainWorld('api', api);