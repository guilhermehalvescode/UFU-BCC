document.addEventListener("DOMContentLoaded", e => {
    const rows = document.querySelectorAll(".eval");
    let notaFinal = 0, somaPesos = 0;
    rows.forEach(row => {
        const peso = parseFloat(row.querySelector(".peso").textContent);
        somaPesos += peso;
        const nota = parseFloat(row.querySelector(".nota").textContent);
        notaFinal += (nota * peso);
    });
    notaFinal /= somaPesos;
    const nf = document.querySelector("#mp");
    nf.textContent = String(notaFinal.toFixed(2));
});
//nota final conforme a tabela