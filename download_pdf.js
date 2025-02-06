let jspdf = document.createElement("script");

jspdf.onload = function () {

    let images = document.getElementsByTagName("img");

    const pdf = new jsPDF({
        orientation: 'landscape',
        unit: 'px',
        format: [images[0].naturalWidth, images[0].naturalHeight],
    });

    Array.from(images).forEach((img, index) => {
        if (!/^blob:/.test(img.src))
            return;

        let can = document.createElement('canvas');
        can.width = img.naturalWidth;
        can.height = img.naturalHeight;
        can.getContext("2d").drawImage(img, 0, 0, img.naturalWidth, img.naturalHeight);

        pdf.addImage(can.toDataURL("image/jpeg", 1.0), 'JPEG', 0, 0, pdf.internal.pageSize.getWidth(), pdf.internal.pageSize.getHeight());
        pdf.addPage();
    });

    pdf.deletePage(pdf.internal.getNumberOfPages());

    pdf.save(`download.pdf`);
};

jspdf.src = 'https://cdnjs.cloudflare.com/ajax/libs/jspdf/1.5.3/jspdf.debug.js';
document.body.appendChild(jspdf);
