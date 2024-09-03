import { defineConfig } from 'vite'
import { svelte } from '@sveltejs/vite-plugin-svelte'
import path from 'path';

// https://vitejs.dev/config/
export default defineConfig({
  base: process.env.DEV_ENV == 'true' ? '/' : './',
  build: {
    outDir: 'electron/build'
  },
  plugins: [svelte()],
  resolve: {
    alias: {
        '@': path.resolve(__dirname, 'src'),
        '@components': path.resolve(__dirname, 'src/components'),
        '@db': path.resolve(__dirname, 'src/db'),
        '@lib': path.resolve(__dirname, 'src/lib'),
    }
  }
})
