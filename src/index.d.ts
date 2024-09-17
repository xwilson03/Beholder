interface api {
    saveDB: () => void
};

declare global {
    interface Window {
        api: api
    }
}