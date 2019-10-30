const URL = 'https://api.mercadolibre.com/sites/MLB/search?';

const onSearchSuccess = (data) => {
    console.log(data)
    const elementList = '.products-list';

    const hasResult = data && data.results.length > 0;

    if (hasResult) {
        drawResultList(elementList, data.results)
    } else {
        withoutResults(elementList)
    }
        
    
};

const onError = (errors) => {
    console.error('errors', errors);
};

const drawResultList = (element, data) => {
    for (const item in data) {
        $('<li />', { class: 'item' }).appendTo(element);
        $('<a />', { href: data[item].permalink }).appendTo(`${element} li`);
        $('<img />', { src: data[item].thumbnail }).appendTo(`${element} li a`);
        $('<span />', { text: data[item].title, class: 'name' }).appendTo(`${element} li a`);
        $('<span />', { text: data[item].price, class: 'price' }).appendTo(`${element} li a`);
   }
};

const withoutResults = (element) => {
    $(element).append(
        $('<li class="without-results"/>')
            .html('Nenhum resultado encontrado.')
    );
};

const getSearchTerms = (terms) => {
    $.get(`${URL}q=${terms}`)
	    .done((pResult) => onSearchSuccess(pResult) )
	    .fail((pErr) => onError(pError));
}


$(document).ready(() => {
    
    $("#search-btn").click(() => {
        const searchTerms = $("#search").val();
        getSearchTerms(searchTerms)
        
    })
    
});