const puppeteer = require('puppeteer');

let args = [...process.argv].slice(2);
const queryText = args.length ?  args.join(" ") : "Nepal"

const baseWikiUrl = `https://en.wikipedia.org/wiki/`;
const fileName = queryText.replace(/\s/g,"_");
const noArticleConfirmText = "Wikipedia does not have an article with this exact name.";

(async () => {
  try{
    console.log("Opening headless browser.");
    const browser = await puppeteer.launch();

    console.log("Opening new page.");
    const page = await browser.newPage();

    let url = baseWikiUrl + queryText;
    console.log(`Navigating to ${url}`);

    await page.goto(url,{waitUntil:'networkidle0'});
    console.log("Checking if the article exist or not.");
    
    // the '.mbox-text > b' selector is available in the wikipedia page if the article is not found.
    const mBox = await page.$('.mbox-text > b'); 
    if(mBox){
      const iText = await page.evaluate(br=>br.innerText,mBox);
      if(iText && iText === noArticleConfirmText){
        throw new Error(noArticleConfirmText);
      }
  }

    console.log("Article found and processing the file operations.");
    await page.screenshot({ path:`./ss/${fileName}.png`,fullPage:true});
    await page.pdf({path:`./pdf/${fileName}.pdf`,format:'a4'});
    
    await browser.close();
  }catch(error){
    console.log(error.message);
  }finally{
    console.log("Program terminated !!!")
    process.exit(process.exitCode)
  }
})();