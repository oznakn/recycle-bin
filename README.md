## recycle-bin

Pure NAPI version of [trash](https://www.npmjs.com/package/trash).

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
