const path = require('path')
const fs = require('fs')

const objfilePath = path.join(__dirname, '..', 'src')
if(!fs.existsSync(objfilePath)) {
  console.error('Cannot clean. Path to .o files DNE.')
}

const oFile = (filename) => filename.endsWith(".o")
const getOFiles = (dir) => fs.readdirSync(dir).filter((f) => oFile(f))

getOFiles(objfilePath).map((f) => fs.unlinkSync(path.join(objfilePath, f)))