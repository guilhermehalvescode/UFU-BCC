window.addEventListener("DOMContentLoaded", () => {
    const h2List = document.querySelectorAll("h2")

    for(let h2 of h2List) {
        h2.addEventListener("click", () => {
            h2.nextElementSibling.style.display = 'none';
        })
        h2.addEventListener("dblclick", () => {
            h2.nextElementSibling.style.display = 'block';
        })
    }
})