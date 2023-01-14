## recycle-bin

Pure NAPI version of [trash](https://www.npmjs.com/package/trash).

### Why?

While bundling the module `trash` with Webpack, the module has to be declared as a external module since it uses binary executables under the hood. This module implements a pure NodeJS NAPI implementation to overcome this issue.

Moreover, due to usage of executables, when `trash` is being used with Electron, some Antivirus softwares detects the executables as malicious software.

### Install

```bash
npm install recycle-bin
```

### Usage

```javascript
import trash from 'recycle-bin';

await trash(['*.png', '!rainbow.png']);
```

## API

### trash(input, options?)

Returns a `Promise`.

#### input

Type: `string | string[]`

Accepts paths and [glob patterns](https://github.com/sindresorhus/globby#globbing-patterns).

#### options

Type: `object`

##### glob

Type: `boolean`\
Default: `true`

Enable globs when matching file paths.
