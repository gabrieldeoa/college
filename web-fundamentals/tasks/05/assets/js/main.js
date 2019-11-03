/*
 * @author Gabriel de O. Araujo
*/
const URL = 'https://api.mercadolibre.com/sites/MLB/';

const onSearchProductsSuccess = (data, element) => {
    const message = 'Nenhum produto encontrado';
    const hasResult = data && data.results.length > 0;
    const query = data.query;
    const qty = data.paging && data.paging.total;

    if (hasResult) {
        drawProductList(element, data.results);
        showProductsResults(query, qty);
    } else {
        withoutResults(element, message);
    }  
};

const onSearchCategoriesSuccess = (data, element) => {
    const message = 'Nenhuma categoria encontrada';

    if (data) {
        drawCategoryList(element, data);
    } else {
        withoutResults(element, message);
    }

};

const onSearchProductsByCategorySuccess = (data, element) => {
    const message = 'Nenhum produto encontrado';

    if (data) {
        drawProductCards(element, data);
    } else {
        withoutResults(element, message);
    }

};

const onError = (element, errors) => {
    withoutResults(element);
    console.error('errors', errors);
};

const drawProductList = (element, data) => {
    $(element).empty();

    for (const item in data) {
        let id = data[item].id
        let condition = (data[item].condition == 'new') ? 'Novo' : 'Usado';
        let hasOriginalPrice = data[item].original_price !== null;
        let freeShipping = (data[item].shipping.free_shipping) && 'Frete Grátis';

        $('<li />', { class: 'col-sm-6 col-md-4 col-lg-3 item grow', id: id }).appendTo(element);
        $('<a />', { href: data[item].permalink }).appendTo(`#${id}`);
        $('<img />', { src: data[item].thumbnail }).appendTo(`#${id} a`);
        $('<span />', { text: data[item].title, class: 'name' }).appendTo(`#${id} a`);
        
        if(hasOriginalPrice)
            $('<span />', { text: `De: R$ ${data[item].original_price}`, class: 'original-price' }).appendTo(`#${id} a`);

        $('<span />', { text: `Por: R$ ${(data[item].price).toLocaleString('pt-BR')}`, class: 'price' }).appendTo(`#${id} a`);

        $('<span />', { text: condition, class: 'condition' }).appendTo(`#${id} a`);

        if(data[item].shipping.free_shipping)
            $('<span />', { text: freeShipping, class: 'shipping' }).appendTo(`#${id} a`);

   }
};

const drawCategoryList = (element, data) => {
    $(element).empty();

    for (const item in data) {
        $('<li />', { class: 'category', id: data[item].id }).appendTo(element);
        $('<a />', { class: 'dropdown-item', href: '#', text: data[item].name }).appendTo(`#${data[item].id}`);
   }
};

const drawProductCards = (element, data) => {
    const { results } = data;

    for (const item in results) {
        let id =  results[item].id;
        let address = results[item].address;
        let installments = results[item].installments;
        let quantity = installments.quantity;
        let amount = installments.amount;
        
        $('<div>', { class: 'col-xs-12 col-sm-6 col-md-6 col-lg-3 grow product-card', id: id }).appendTo(element);
        $('<a />', { href: results[item].permalink }).appendTo(`#${id}`);
        $('<div>', { class: 'card text-center' }).appendTo(`#${id} a`);
        $('<h5/>', { class: 'card-header', text: results[item].title  }).appendTo(`#${id} div`);
        $('<div/>', { class: 'card-body' }).appendTo(`#${id} .card`);
        $('<img />', { src: results[item].thumbnail }).appendTo(`#${id} .card-body`);
        $('<div>', { class: 'container-price' }).appendTo(`#${id} .card-body`);
        $('<span/>', { class: 'price', text:`R$ ${(results[item].price).toLocaleString('pt-BR')}`}).appendTo(`#${id} .container-price`);
        $('<span/>', { class: 'installments', text:`${quantity}x de ${(amount).toLocaleString('pt-BR')}`}).appendTo(`#${id} .container-price`);
        $('<div>', { class: 'container-stock' }).appendTo(`#${id} .card-body`);
        $('<span/>', { class: 'stock', text:`Estoque: ${results[item].available_quantity}`}).appendTo(`#${id} .container-stock`);
        $('<span/>', { class: 'sold', text:`Vendidos: ${results[item].sold_quantity}`}).appendTo(`#${id} .container-stock`);
        $('<span/>', { class: 'locate', text:`${address.city_name} / ${address.state_name}`}).appendTo(`#${id} .card-body`);
   }
};

const withoutResults = (element, message) => {
    $(element).empty();

    $(element).append(
        $('<li class="col-12 without-results"/>')
            .html(message || 'Nenhum Resultado Encontrado')
    );
};

const searchProducts = (terms, element) => {
    const limit = $('#qty-results').val()
    $.get(`${URL}search?limit=${limit}&q=${terms}`)
	    .done((pResult) => onSearchProductsSuccess(pResult, element) )
	    .fail((pError) => onError(element, pError));
}

const showProductsResults = (query, qty) => {
    $('.search-info .query').text(query);
    $('.search-info .qty').text(qty || 0);
    $('.search-info .info').show();
}

const searchCategories = (element) => {
    $.get(`${URL}categories`)
	    .done((pResult) => onSearchCategoriesSuccess(pResult, element) )
	    .fail((pError) => onError(element, pError));
}

const searchProductsByCategory = (category, element) => {
    $.get(`${URL}search?category=${category}&limit=4`)
	    .done((pResult) => onSearchProductsByCategorySuccess(pResult, element) )
	    .fail((pError) => onError(element, pError));
}

$(document).ready(() => {

    searchCategories('#categories-list');
    searchProductsByCategory('MLB1648', '.category-info');
    searchProductsByCategory('MLB1144', '.category-games');
    searchProductsByCategory('MLB1051', '.category-cell');
    
    
    $("#form-search").submit((e) => {
        e.preventDefault();
        const searchTerms = $(".input-search").val();
        searchProducts(searchTerms, '.products-list');
    });
    
});