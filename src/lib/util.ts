export function blobToFile(blob: Blob, fileName: string): File{
    const file: any = blob;
    file.lastModifiedDate = new Date();
    file.name = fileName

    return file as File;
}