const path = require('path')
const fs = require('fs')
const argv = require('yargs').argv
const cmd = require('node-cmd')
const conf = require('./config')

conf.input = conf.input || 'src/main.cpp'
conf.outputDir = conf.outputDir || 'bin'
conf.output = conf.output || 'index.html'

const inputDir = path.join(__dirname, '..', conf.inputDir || 'src')
if(!fs.existsSync(inputDir)) {
  console.error(`Directory '${inputDir}' does not exist!`)
}

const fullPaths = (inputDir, fileNames) => fileNames.map((f) => path.resolve(__dirname, '..', inputDir, f))
const isFile = (inputDir, file) => fs.lstatSync(fullPaths(inputDir, [file])[0]).isFile()
const getAllCppFiles = (inputDir) => fs.readdirSync(inputDir).filter((f) => isFile(inputDir, f) && f.endsWith(".cpp"))

let input
if(conf.input && typeof conf.input === Array) {
  input = fullPaths(inputDir, conf.input)
} else {
  input = fullPaths(inputDir, getAllCppFiles(inputDir))
}

const output = path.join(__dirname, '..', conf.outputDir, conf.output)
const wasm = conf.wasm ? 'WASM=1' : ''
let buildCmd = `emcc ${input.toString().replace(/,/g, ' ')} -s ${wasm} -o ${output} --std=c++11`

if(conf.template) {
  const template = path.join(__dirname, conf.template)
  buildCmd += ` --shell-file ${template}`
}

console.info('EXEC: ' + buildCmd + '\n')
let build = cmd.get(buildCmd, handleOutput)

function handleOutput(err, data, stderr) {
  if(err) {
    console.error('Error: ', err)
  } else {
    console.log('Build complete! :)')
  }
}