function showMessage(str) {
    const mb = document.querySelector("#messageBox")

    mb.firstChild.textContent = str;
    mb.style.visibility = 'visible';
}

const btn = document.querySelector("#showMessageBox")

btn.addEventListener("click", () => {
    const input = document.querySelector("input");

    showMessage(input.value)
});



const btnShowMessageBox = document.querySelector("#messageBox > button")
btnShowMessageBox.addEventListener("click", () => {
    const mb = document.querySelector("#messageBox")
    mb.style.visibility = 'hidden'
})
